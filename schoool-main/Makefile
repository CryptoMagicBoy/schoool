part3:
		sudo docker pull nginx
		sudo docker run --name dock -dt -p 81:81 nginx
		sudo docker exec -it dock bash -c 'apt update ; apt install -y gcc libfcgi-dev spawn-fcgi make nano ; mkdir /dock'
		sudo docker cp ./server/mini_web_server.c dock:/dock/
		sudo docker cp ./server/Makefile dock:/dock/
		sudo docker cp ./server/nginx/nginx.conf dock:/etc/nginx/nginx.conf
		sudo docker exec -it dock bash -c 'make dock -C /dock/'
		sudo docker exec -it dock bash -c 'spawn-fcgi -p8080 /dock/mini_web_server'
		sudo docker exec -it dock bash -c 'nginx -s reload'

part4:
		sudo docker build -f ./Dockerfile -t estaedmo:docker .
		sudo docker images
		sudo docker run --name docker_part4 -dt -p 80:81 -v "$(shell pwd)"/server/nginx/nginx.conf:/etc/nginx/nginx.conf estaedmo:docker
		sudo docker ps

part5:
		export DOCKER_CONTENT_TRUST=1
		sudo docker build -f ./Dockerfile2 -t estaedmo:docker .
		sudo docker run --name docker_part5 -dt -p 80:81 -v "$(shell pwd)"/server/nginx/nginx.conf:/etc/nginx/nginx.conf estaedmo:docker
		sudo docker ps

part6:
		sudo docker-compose build
		sudo docker-compose up -d

status:
		sudo docker images -a
		sudo docker ps -a

clean:
		sudo docker system prune -a
