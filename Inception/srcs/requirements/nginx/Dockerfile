FROM alpine:latest

RUN apt-get update && apt-get install -y nginx

COPY default.conf /etc/nginx/nginx.conf

COPY ssl.crt /usr/nginx
COPY ssl.pass /usr/nginx
COPY ssl.key /usr/nginx
EXPOSE 443


ENTRYPOINT nginx -d 'daemon off;'