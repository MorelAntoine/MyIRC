# MyIRC

IRC recode (TCP protocol, socket, C) base on RFC 1459 (Internet Relay Chat Protocol)

    Dev period: 24 may 2017 - 11 june 2017

Server
======

> Usage

        ./server port
        
            - port is the port number on which the server socket is listening.
            
Client
======

> Functionalities

        • /server $host[:$port]: connects to a server

        • /nick $nickname: defines the user’s nickname in the server

        • /list [$string]: lists the server’s available channels.
            (Only display the channels that contain the $string string (when specified))

        • /join $channel: joins a server’s channel

        • /part $channel: leaves a channel

        • /users: lists the nicknames of the users that are connected to the server

        • /names $channel: lists the nicknames of the users connected to the channel

        • $message: sends a message to all of the users that are connected to the channel

        • /msg $nickname $message: sends a message to a specific user

> Usage

        ./client
        
Made By
=======

> Antoine MOREL

> Dylan DEU