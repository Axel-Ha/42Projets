PATH_DOCKER = docker compose -f ./srcs/docker-compose.yml

all: up-build
 
dvolumes:
	sudo mkdir -p /home/ahalifa/data/wordpress
	sudo mkdir -p /home/ahalifa/data/mysql
stop:
	$(PATH_DOCKER) stop

up: dvolumes
	$(PATH_DOCKER) up -d

up-build: dvolumes
	$(PATH_DOCKER) up -d --build

build: dvolumes
	$(PATH_DOCKER) up build

down:
	$(PATH_DOCKER) down

ps:
	$(PATH_DOCKER) ps

clean:
	$(PATH_DOCKER) down -v --rmi all --remove-orphans

clean-images:
	@images=$$(docker images --filter reference=srcs-* -q); \
	if [ -n "$$images" ]; then docker rmi -f $$images; fi

fclean: clean clean-images

logs:
	$(PATH_DOCKER) logs -f

users:
	docker exec -it wordpress wp user list --allow-root

posts:
	docker exec -it mariadb  mariadb -u root -p -e "SELECT post_title from wp_db_name.wp_posts;"

clean-correction:
	docker stop $$(docker ps -qa) 2>/dev/null || true; \
	docker rm $$(docker ps -qa) 2>/dev/null || true; \
	docker rmi -f $$(docker images -qa) 2>/dev/null || true; \
	docker volume rm $$(docker volume ls -q) 2>/dev/null || true; \
	docker network rm $$(docker network ls -q) 2>/dev/null || true
	sudo rm -rf /home/ahalifa/data/* 
	

re: fclean up-build

.PHONY: all stop up up-build build ps down clean clean-images clean-correction fclean logs posts users re
