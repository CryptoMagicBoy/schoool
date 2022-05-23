#!/bin/bash

gcc mini_web_server.c -lfcgi -o mini_web_server
spawn-fcgi -p8080 ./mini_web_server
service nginx start

/bin/bash
