#!/usr/bin/env bash

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
DB_PASSWORD=$(cat /run/secrets/db_password)

if [ ! -d "/var/lib/mysql/${DB_NAME}" ]; then

    echo "[INFO] Initializing MariaDB data directory..."
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql

    echo "[INFO] Configuring initial databases and users..."

    mariadbd --user=mysql --bootstrap <<EOF
FLUSH PRIVILEGES;

CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;
CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';

ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';

FLUSH PRIVILEGES;
EOF

fi

echo "[INFO] Starting main MariaDB service..."
exec mariadbd --user=mysql --port=3306 --bind-address=0.0.0.0 --console