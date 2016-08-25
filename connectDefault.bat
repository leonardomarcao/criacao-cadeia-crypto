::main connections using already existing credentials
::this connections was using credentials exiting
NET USE M: \\REPOSITORY\maps1$  /PERSISTENT:YES ::for connect in repository and persistent connection
NET USE N: \\SERVER\dados$ /PERSISTENT: YES ::for connect in server\dados and persistent connection