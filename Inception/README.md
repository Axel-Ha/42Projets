*This activity has been created as part of the 42 curriculum by ahalifa*

## Description
This project aims to set up an infrastructure using Docker Compose. It comprises several custom-built services (NGINX, WordPress, and MariaDB) that communicate with each other.

## Project Description
Docker is an open-source platform that allows developers to package applications and their dependencies into isolated containers.

### Virtual Machines vs Docker
A Virtual Machine virtualizes an entire hardware and runs a full operating system, which consumes significant system resources and takes longer to boot. Docker containers share the host system's kernel, making them lightweight, fast to start, easily shareable, and simple to maintain.

### Secrets vs Envirnonment Variables
Environment variables are key-value pairs stored in plain text. Docker Secrets, provide a secure mechanism to inject sensitive information into containers without exposing them.

### Docker Network vs Host Network 
Using a custom Docker Network creates an isolated network where containers can securely communicate using their service names as hostnames. Using the Host Network bypasses network isolation by sharing the host's IP and ports directly, which increases security risks and risks port conflicts.

### Docker Volumes vs Bind Mounts
Docker Volumes are managed entirely by Docker and stored in a designated area of the host filesystem (`/var/lib/docker/volumes/` or custom storage drivers). They ensure data persistence, simplify backups, and isolate container data from host modifications. Bind Mounts map a specific file or directory from the host filesystem into the container, allowing the container to read or modify host files directly.

## Instructions
Before launching the project, you must set up both the environment variables and secrets.  

### 1. Environment Variables
Create a `.env` file in the `srcs` directory with your non-sensitive configuration:

```env
# Database settings
DB_USER=your_database_user
DB_NAME=your_database_name

# WordPress settings
WORDPRESS_ADMIN=your_admin_username
WORDPRESS_MAIL_ADMIN=admin@example.com
WORDPRESS_USER=your_regular_user
WORDPRESS_MAIL_USER=user@example.com
```  
### 2. Docker Secret
Create a `secrets/` directory at the root of the repository and add the following files containing only their respective passwords in plain text:
```env
secrets/db_password.txt
secrets/db_root_password.txt
secrets/wp_admin_password.txt
secrets/wp_user_password.txt
```


To build and launch the infrastructure, run the following command from the repository root:
```bash
make 
or
make up-build
```
Once the containers and volumes are running, you can access the website at:
`https://ahalifa.42.fr`  
Log in using the credentials defined in your .env file to manage and publish WordPress posts.

## Resources  
- A lot of website was used.  
- AI tools were used as a senior developer pair-programmer to guide me throught the project.


