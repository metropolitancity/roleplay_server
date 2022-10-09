CREATE TABLE IF NOT EXISTS `users_vehicles`(
    `id` VARCHAR(64) PRIMARY KEY,
    `user_id` INT(11) NOT NULL,
    `model` INT(3) NOT NULL,
    `spawn_x` FLOAT NOT NULL,
    `spawn_y` FLOAT NOT NULL,
    `spawn_z` FLOAT NOT NULL,
    `spawn_a` FLOAT NOT NULL,
    `interior` INT(11) DEFAULT 0,
    `world` INT(11) DEFAULT 0,
    `door` BOOLEAN  DEFAULT 0,
    `color1` INT(3) NOT NULL,
    `color2` INT(3) NOT NULL,
    `fuel` FLOAT NOT NULL,
    `km` FLOAT DEFAULT 0,
    foreign key (`user_id`) references `users`(`id`),
    `updated_at` DATETIME DEFAULT CURRENT_TIMESTAMP() ON UPDATE CURRENT_TIMESTAMP(),
    `created_at` DATETIME DEFAULT CURRENT_TIMESTAMP
)ENGINE = INNODB CHARSET="utf8" COLLATE="utf8_general_ci";