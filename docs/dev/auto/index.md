# Automation and Crawler

## Automation

### Telnet

The sample code to use python to perform firmware upgrading via telnet protocol.

~ TBD ~


### SSH

The sample code to use python to perform  firmware upgrading via ssh protocol.

``` python
#!/usr/bin/env python3
import paramiko
username = "ed"
password = "11111111"
hostname = "127.0.0.1"
port = 22
try:
    client = paramiko.SSHClient()
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    client.connect(hostname, port, username, password)
    t = client.get_transport()
    sftp = paramiko.SFTPClient.from_transport(t)
    stdin, stdout, stderr = client.exec_command('ls -al')
    result = stdout.readlines()
    print(result)
except Exception:
    print('Exception!!')
    raise
```

~ TBD ~