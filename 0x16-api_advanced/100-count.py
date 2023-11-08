#!/usr/bin/python3
""" Module for a function that queries the Reddit API recursively."""


import requests

def count_words(subreddit, word_list, after=None, counts={}):
    base_url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'Mozilla/5.0'}

    params = {'limit': 100, 'after': after}
    response = requests.get(base_url, params=params, headers=headers)

    if response.status_code == 200:
        data = response.json().get('data')
        after = data.get('after')
        children = data.get('children')
        for post in children:
            title = post.get('data').get('title').lower()
            for word in word_list:
                word = word.lower()
                if word in counts:
                    counts[word] += title.count(word)
                else:
                    counts[word] = title.count(word)

        if after is not None:
            count_words(subreddit, word_list, after, counts)
        else:
            sorted_counts = sorted(counts.items(), key=lambda item: (-item[1], item[0]))
            for word, count in sorted_counts:
                if count > 0:
                    print(f"{word}: {count}")
    else:
        print("Invalid subreddit or no posts match")

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Example: {} programming 'python java javascript'".format(sys.argv[0]))
    else:
        subreddit = sys.argv[1]
        word_list = sys.argv[2].split()
        count_words(subreddit, word_list)
