CREATE TABLE IF NOT EXISTS `property`(
    `id` INT(11) PRIMARY KEY AUTO_INCREMENT,
    `name` VARCHAR(32) NOT NULL,
    `entrance_x` FLOAT NOT NULL,
    `entrance_y` FLOAT NOT NULL,
    `entrance_z` FLOAT NOT NULL,
    `entrance_a` FLOAT NOT NULL,
    `exit_x` FLOAT NOT NULL,
    `exit_y` FLOAT NOT NULL,
    `exit_z` FLOAT NOT NULL,
    `exit_a` FLOAT NOT NULL,
    `interior` INT(3) NOT NULL,
    `mapicon` INT(11) NOT NULL,
    `updated_at` DATETIME DEFAULT CURRENT_TIMESTAMP() ON UPDATE CURRENT_TIMESTAMP(),
    `created_at` DATETIME DEFAULT CURRENT_TIMESTAMP
)ENGINE = INNODB CHARSET="utf8" COLLATE="utf8_general_ci";