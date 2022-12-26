FROM		debian:buster

RUN 		apt-get update -y && \
			apt-get install -y nginx openssl
							
COPY		./conf/default.conf /etc/nginx/conf.d/default.conf

RUN			openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:2048 \
			-subj "/C=KR/ST=Seoul/O=42Seoul/OU=GON" \
			-keyout /etc/ssl/private/server.key -out /etc/ssl/certs/server.crt

EXPOSE		443

ENTRYPOINT	["nginx", "-g", "daemon off;"]

