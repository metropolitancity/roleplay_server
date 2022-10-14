CREATE TABLE IF NOT EXISTS `users`(
    `id` INT(11) PRIMARY KEY AUTO_INCREMENT,
    `name` VARCHAR(25) NOT NULL UNIQUE,
    `email` VARCHAR(64) NOT NULL UNIQUE,
    `password` VARCHAR(64) NOT NULL,
    `admin` INT(1) DEFAULT 0,
    `skin` INT(3) NOT NULL,
    `gender` INT(1) NOT NULL,
    `spawn_x` FLOAT DEFAULT 0.0,
    `spawn_y` FLOAT DEFAULT 0.0,
    `spawn_z` FLOAT DEFAULT 0.0,
    `spawn_a` FLOAT DEFAULT 0.0,
    `interior` INT(11) DEFAULT 0,
    `world` INT(11) DEFAULT 0,
    `health` FLOAT DEFAULT 100,
    `armour` FLOAT DEFAULT 0,
    `updated_at` DATETIME DEFAULT CURRENT_TIMESTAMP() ON UPDATE CURRENT_TIMESTAMP(),
    `created_at` DATETIME DEFAULT CURRENT_TIMESTAMP()
)ENGINE = INNODB CHARSET="utf8" COLLATE="utf8_general_ci";