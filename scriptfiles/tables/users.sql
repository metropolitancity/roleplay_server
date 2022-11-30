CREATE TABLE IF NOT EXISTS `users`(
    `id` INT(11) PRIMARY KEY AUTO_INCREMENT,
    `name` VARCHAR(25) NOT NULL UNIQUE,
    `email` VARCHAR(64) NOT NULL UNIQUE,
    `password` VARCHAR(64) NOT NULL,
    `money` INT(11) DEFAULT 0,
    `admin` INT(1) DEFAULT 0,
    `skin` INT(3) NOT NULL,
    `gender` INT(1) NOT NULL,
    `coins` INT(11) DEFAULT 0,
    `spawn_x` FLOAT DEFAULT 0.0,
    `spawn_y` FLOAT DEFAULT 0.0,
    `spawn_z` FLOAT DEFAULT 0.0,
    `spawn_a` FLOAT DEFAULT 0.0,
    `interior` INT(11) DEFAULT 0,
    `world` INT(11) DEFAULT 0,
    `health` FLOAT DEFAULT 100,
    `armour` FLOAT DEFAULT 0,
    `whitelist` INT(1) DEFAULT 0,
    `discord_id` VARCHAR(32) DEFAULT NULL,
    `hunger` FLOAT DEFAULT 100,
    `thirst` FLOAT DEFAULT 100,
    `sleep` FLOAT DEFAULT 100,
    `updated_at` DATETIME DEFAULT CURRENT_TIMESTAMP() ON UPDATE CURRENT_TIMESTAMP(),
    `created_at` DATETIME DEFAULT CURRENT_TIMESTAMP()
)ENGINE = INNODB CHARSET="utf8" COLLATE="utf8_general_ci";