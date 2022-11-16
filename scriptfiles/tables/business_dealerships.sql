CREATE TABLE IF NOT EXISTS `business_dealerships`(
    `id` INT(11) PRIMARY KEY AUTO_INCREMENT,
    `name` VARCHAR(32) NOT NULL,
    `user_id` INT(11) DEFAULT NULL UNIQUE,
    `price` INT(11) NOT NULL,
    `x` FLOAT NOT NULL,
    `y` FLOAT NOT NULL,
    `z` FLOAT NOT NULL,
    `vspawn_x` FLOAT NOT NULL,
    `vspawn_y` FLOAT NOT NULL,
    `vspawn_z` FLOAT NOT NULL,
    `vspawn_a` FLOAT NOT NULL,
    FOREIGN KEY (`user_id`) REFERENCES `users`(`id`),
    `updated_at` DATETIME DEFAULT CURRENT_TIMESTAMP() ON UPDATE CURRENT_TIMESTAMP(),
    `created_at` DATETIME DEFAULT CURRENT_TIMESTAMP
)ENGINE = INNODB CHARSET="utf8" COLLATE="utf8_general_ci";