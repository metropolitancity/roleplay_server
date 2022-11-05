CREATE TABLE IF NOT EXISTS `business_dealerships_vehicles`(
    `id` CHAR(36) NOT NULL DEFAULT (uuid()) PRIMARY KEY,
    `dealership` INT(11) NOT NULL,
    `vehicle` VARCHAR(64) DEFAULT NULL UNIQUE,
    `model` INT(3) NOT NULL,
    `price` INT(11) NOT NULL,
    `price_sell` INT(11) NOT NULL,
    `type` INT(1) NOT NULL,
    `updated_at` DATETIME DEFAULT CURRENT_TIMESTAMP() ON UPDATE CURRENT_TIMESTAMP(),
    `created_at` DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (`dealership`) REFERENCES `business_dealerships`(`id`),
    FOREIGN KEY (`vehicle`) REFERENCES `users_vehicles`(`id`)
)ENGINE = INNODB CHARSET="utf8" COLLATE="utf8_general_ci";