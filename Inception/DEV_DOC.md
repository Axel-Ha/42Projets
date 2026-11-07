# Dev Documentation

This document provides technical instructions for developers to set up, build, manage and inspect the project infrastructure.

## 1. Environment Setup et Prerequisites

### Prerequisites
* **Operating System** : Linux/Debian Environment
* **Software** : `Docker`, `docker compose plugin`, `make` 

### Configuration secrets file

All environment configurations and sensitive credentials are separated between the `.env` file (`srcs/.env`) and the `secrets/` directory at the root of the project.

### Environment Variables (`srcs/.env`)
Contains non-sensitive configuration values:

- **Domain & Database:**
  - `DB_NAME`: Database name (`${DB_NAME}`)
  - `DB_USER`: Database user login (`${DB_USER}`)

- **WordPress Users:**
  - `WORDPRESS_ADMIN`: Administrator username (`${WORDPRESS_ADMIN}`)
  - `WORDPRESS_MAIL_ADMIN`: Administrator email (`${WORDPRESS_MAIL_ADMIN}`)
  - `WORDPRESS_USER`: Regular user username (`${WORDPRESS_USER}`)
  - `WORDPRESS_MAIL_USER`: Regular user email (`${WORDPRESS_MAIL_USER}`)

---

### Secrets (`secrets/`)
Contains plain-text files storing sensitive passwords, mounted securely via Docker Secrets:

- **Database Secrets:**
  - `secrets/db_password.txt`: Database user password
  - `secrets/db_root_password.txt`: MariaDB root password

- **WordPress Secrets:**
  - `secrets/wp_admin_password.txt`: Administrator user password
  - `secrets/wp_user_password.txt`: Regular user password

## 2. Building and Launching
All operations are managed using the included `Makefile` at the root of the repository. Or you can use the command of docker compose (srcs/docker-compose.yml).

**Build the stack**:
```bash
make build

or 

docker compose build
```

**Lauch the stack**:
```bash
make up

or 

docker compose up -d
```

## 3. Managing containers and volumes

**Removes the containers and volumes**:
```bash
make clean
```

**Removes the images**:
```bash
make clean-images
```

**Removes images, containers and volumes**:
```bash
make fclean
```

**Rebuild from scratch**:
```bash
make re
```

**Enter Database**
```bash
docker exec -it mariadb mariadb -u root -p
```

## 4. Data Storage and Persistence
Data persistence is guaranteed through dedicated Docker volumes defined in docker-compose.yml
* Wordpress files (wordpress-data)  
    * Mounted at `/var/www/html` in both `wordpress` and `nginx` containers.
    * Ensure that Nginx and PHP-FPM shares the exact same filesystem context.

* MariaDB data base (mysql-data)  
    * Mounted at `/var/lib/mysql` in  `mariadb` container.
    * Preserves database records, user profile, posts, and system configuration accross container restarts.

