# User Documentation

This document will explain how to interact, manage and verify the services provided by the stack.

## 1. Services Provided

**Nginx**: Serving as the secure web server entry point.  
**WordPress + PHP**: Content management system (CMS), service to create article.  
**MariaDB**: The database management system storing website data.  


## 2. Starting and Stopping the Services

All operations are managed using the included `Makefile` at the root of the repository. Or you can use the command of docker compose (`srcs/docker-compose.yml`).

**Start the stack**:
```bash
make up

or 

docker compose up -d 
```

**Stop the stack**:
```bash
make stop

or 

docker compose stop 
```

## 3. Accessing the website and Administration Panel

To access the website enter the url: `https://ahalifa.42.fr`

To access the admin dashboard: `https://ahalifa.42.fr/wp-admin`

## 4. Locating and Managing Credentials

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
  
## 5. Checking service health  

1. Check running container :  
    ```bash
    make ps

    or 

    docker ps 
    ```

2. Inspect live logs : 
    ```bash
    make logs

    or 

    docker logs 
    ```
