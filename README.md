Comp 8005 Computer Systems Technology March 2018
Network and Security Applications Development
Final Project

# Due
April 9, 1200 hrs. (You may work in groups of two)

# Objective:
To design and develop a network application that uses advanced TCP/IP programming techniques.
To design and implement a minimum-functionality “Port Forwarder” using any language of your choice.
A maximum-functionality port forwarder could include a proxy server, caching, etc.

forward traffic addressed to one port to another requested port on another IP
Only TCP is required
Load port>IP:port combo from a file
handle multiple forwards
handle multiple connections on all forwards
handle traffic & connection load

# Submit
Design, Source, Executable
User Manual
Test plan & results
Present in class

# Design
identify required fields; 
    tcp/udp/both, local port, remote port, remote address
create config file
load config file
for each line
    separate fields
    spin off thread ->create tunnel(lport,rport,raddr)
    wait for connection
        spin off process
        handle connection
        close connection

# Pseudo
load config
for each line
    spin off process
    create tunnel
    listen for connection
    for each connection request
        spin off process
        handle connection
        close connection
        kill process
    

# How To
Identify remote machine(s) to connect to
Ensure desired port(s) is/are available
Edit 'configure' file to reflect forwards
(type:local-port:remote-port:remote-address)
launch app
observe connections status

# Test Plan
Load configuration from log file
Establish TCP tunnels for all requested ports
unable to connect
port not avalable
[collect and buffer if closed]

# Test Cases
## Load configuration from file

## Create tunnel for requested pairings
## Notify if requested port unavailable
## Notify if remote connection unavailable
## Multiple Clients
## Multiple Tunnels
## Multiple Clients x Tunnels