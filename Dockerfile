FROM nginx

COPY ./server/mini_web_server.c /mini_web_server/
COPY ./server/4.sh /mini_web_server/
COPY ./server/nginx/nginx.conf /etc/nginx/nginx.conf

RUN apt-get update ; \
    apt-get install -y gcc  \
    make \
    spawn-fcgi \
    libfcgi-dev ;

WORKDIR /mini_web_server/

ENTRYPOINT [ "./4.sh" ]