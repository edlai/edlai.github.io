#!/usr/bin/env python3
import paramiko
username = "ed"
password = "1111qqqq"
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
