FROM	alpine:3.12.0
# install
RUN	apk update
RUN	apk add nginx vim openssl
# Creating folder
RUN	mkdir -p /run/nginx
RUN	mkdir /www
# Create SSL certificate
RUN     openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=huchoi/CN=192.168.99.117" \
        -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
# copy
COPY	web/* /www/
COPY    nginx.conf /etc/nginx
# port
EXPOSE  80 443
# start
COPY	start.sh /start.sh
RUN	chmod 777 /start.sh
CMD	sh /start.sh
