FROM    alpine:3.12.0
#install basic
RUN     apk update
RUN     apk add wget nginx
RUN     apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session php-ctype

RUN     mkdir -p /run/nginx
COPY	resolv.conf /etc/resolv.conf
#setting wordpress
RUN     mkdir /www
#RUN     wget -c  https://wordpress.org/latest.tar.gz -O - | tar -xz -C /www
#COPY	latest.tar.gz /www
RUN		cd www
#RUN		tar -xvf latest.tar.gz
RUN		cd ..
# copy files
COPY	wp-config.php /www/wordpress/wp-config.php
COPY	nginx.conf /etc/nginx/nginx.conf
# port
EXPOSE	5050
# start
COPY	start.sh /start.sh
RUN		chmod 777 /start.sh
CMD		sh /start.sh
