3:
		docker pull nginx
		docker run --name dock -dt -p 81:81 nginx
		docker exec -it dock bash -c 'apt update ; apt install -y gcc libfcgi-dev spawn-fcgi make nano ; mkdir /dock'
		docker cp ./server/mini_web_server.c dock:/dock/
		docker cp ./server/Makefile dock:/dock/
		docker cp ./server/nginx/nginx.conf dock:/etc/nginx/nginx.conf
		docker exec -it dock bash -c 'make dock -C /dock/'
		docker exec -it dock bash -c 'spawn-fcgi -p8080 /dock/mini_web_server'
		docker exec -it dock bash -c 'nginx -s reload'

4:
		docker build -f ./Dockerfile -t ldormamm:dockkk .
		docker run --name my_server -dt -p 80:81 -v $(shell pwd)/server/nginx/nginx.conf:/etc/nginx/nginx.conf ldormamm:dockkk

5:
		docker build -f ./Dockerfile2 -t ldormamm:dockkk .
		docker run --name my_server -dt -p 80:81 -v $(shell pwd)/server/nginx/nginx.conf:/etc/nginx/nginx.conf ldormamm:dockkk

6:
		docker-compose build
		docker-compose up

clean:
		docker system prune -a

check:
		docker images -a
		docker ps -a