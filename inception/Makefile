all : up

up :
	sudo mkdir -p /home/ycha/data/wordpress /home/ycha/data/database
	sudo docker-compose -f srcs/docker-compose.yml up -d --build
	sudo echo "127.0.0.1	ycha.42.fr" > /etc/hosts

down :
	sudo docker-compose -f srcs/docker-compose.yml down

fdown :
	sudo docker stop $$(sudo docker ps -a -q)
	sudo docker rm $$(sudo docker ps -a -q)
	sudo docker rmi -f $$(sudo docker images -q)
	sudo docker system prune -f
	sudo rm -rf /home/ycha/data /etc/hosts

ps :
	sudo docker-compose -f srcs/docker-compose.yml ps

stop_wp :
	sudo docker stop c_wordpress
	sudo docker rm c_wordpress
	sudo docker rmi -f wordpress
	sudo rm -rf /home/ycha/data/wordpress

exec_db :
	sudo docker exec -it c_mariadb bash

exec_wp :
	sudo docker exec -it c_wordpress bash

exec_nx :
	sudo docker exec -it c_nginx bash

log_db :
	sudo docker logs -t c_mariadb

log_nx :
	sudo docker logs -t c_nginx

log_wp :
	sudo docker logs -t c_wordpress

