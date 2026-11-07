FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y nginx
RUN apt-get install -y openssl

RUN mkdir -p /usr/nginx

COPY default.conf /etc/nginx/conf.d/default.conf

WORKDIR /usr/nginx

RUN openssl req -new -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
    -out ssl.crt -keyout ssl.key \
    -subj "/C=FR/CN=ahalifa.42.fr"
EXPOSE 443


CMD ["nginx", "-g", "daemon off;"]