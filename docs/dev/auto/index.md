# Automation and Crawler

There are around few steps as following for firmware development and verification. Firmware RnD can make up a script to do so automatically.

1. Firmware Development
    - SSH to Build Server (Host) to build firmware code.
2. Firmware Deployment
    - TELNET to CPE (Target) to updage the firmware in bootload mode or or in kernel mode.
    - or submit a HTTP POST to updage new firmware.
3. Provisioning
    - submit a HTTP POST request to change the current setting.
4. Verification
    -  submit a HTTP GET request to get the current setting.

## Automation

### TELNET

The sample code shows how to login Router and execute `ls` command.

``` python
import time
import telnetlib
import struct
from telnetlib import DO, DONT, IAC, WILL, WONT, NAWS, SB, SE

MAX_WINDOW_WIDTH = 65000  # Max Value: 65535
MAX_WINDOW_HEIGHT = 5000

host = "192.168.2.1"
user = "root"
passwd = "11111111"

def set_max_window_size(tsocket, command, option):
    """
    Set Window size to resolve line width issue
    Set Windows size command: IAC SB NAWS <16-bit value> <16-bit value> IAC SE
    --> inform the Telnet server of the window width and height.
    Refer to https://www.ietf.org/rfc/rfc1073.txt
    :param tsocket: telnet socket object
    :param command: telnet Command
    :param option: telnet option
    :return: None
    """

    if option == NAWS:
        print(">>>>>>>>>>>>>>>>>> NAWS")
        width = struct.pack('H', MAX_WINDOW_WIDTH)
        height = struct.pack('H', MAX_WINDOW_HEIGHT)
        tsocket.send(IAC + WILL + NAWS)
        tsocket.send(IAC + SB + NAWS + width + height + IAC + SE)
    # -- below code taken from telnetlib source
    elif command in (DO, DONT):
        print(">>>>>>>>>>>>>>>>>> WONT")
        tsocket.send(IAC + WONT + option)
    elif command in (WILL, WONT):
        print(">>>>>>>>>>>>>>>>>> DONT")
        tsocket.send(IAC + DONT + option)

command_arr = ["ls -ls", "exit"]

tn = telnetlib.Telnet(host, 23, 5)
tn.set_debuglevel(2)

tsocket = tn.get_socket()
tn.set_option_negotiation_callback(set_max_window_size)

tn.read_until("login:")
tn.write(user + "\n")

tn.read_until("Password: ")
tn.write(passwd + "\n")

for command in command_arr :
    tn.write(command + "\n")

print (tn.read_all())

tn.close()
```


### SSH

The sample code shows how to login Server and execute `ls` command.

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

## HTTP REQUEST

- [curl](https://curl.se/): command line tool and libraryfor transferring data with URLs.
- [Python Requests](https://docs.python-requests.org/en/master/): an elegant and simple HTTP library for Python, built for human beings.
- [axios](https://github.com/axios/axios): Promise based HTTP client for the browser and node.js.
- [Postman](https://www.postman.com/): The Collaboration Platform for API Development.

### Method

CURD      | SQL    |  HTTP Method         |
----------|:------:|----------------------|
Create    | INSERT |  PUT / POST          |
Delete    | DELETE |  DELETE              |
Read      | SELECT |  GET                 |
Update    | UPDATE |  PUT / POST / PATCH  |

#### GET

- Grab all API

``` console
$ curl -H 'Cache-Control: no-cache' http://192.168.0.1:8000/api/
```

- Grab current settings

``` console
$ curl -H 'Cache-Control: no-cache' http://192.168.0.1:8000/api/users
```
#### POST

- Modify the current settings

``` console
$ curl -H 'Cache-Control: no-cache' http://localhost:8000/api/users/[{"username": "joe", "email": "joe@example.com"}]
```

- Upload a File

``` console
$ curl -X POST -H 'Cache-Control: no-cache' -F "file_uploaded=@output/fw.bin" http://192.168.0.1:8000/api/upload/
```

### Selenium

### Misc

- CSRF token

~ TBD ~