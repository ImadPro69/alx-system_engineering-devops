# Kill process KillMeNow

exec { 'pkill':
  command  => 'pkill killmenow',
  provider => 'shell',
}
