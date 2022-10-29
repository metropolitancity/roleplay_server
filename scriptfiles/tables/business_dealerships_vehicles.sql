CREATE TABLE IF NOT EXISTS `business_dealerships_vehicles`(
    `id` VARCHAR(64) PRIMARY KEY,
    `dealership` INT(11) NOT NULL,
    `vehicle` VARCHAR(64) NOT NULL UNIQUE,
    `price` INT(11) NOT NULL,
    `price_sell` INT(11) NOT NULL,
    `updated_at` DATETIME DEFAULT CURRENT_TIMESTAMP() ON UPDATE CURRENT_TIMESTAMP(),
    `created_at` DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (`dealership`) REFERENCES `business_dealerships`(`id`),
    FOREIGN KEY (`vehicle`) REFERENCES `users_vehicles`(`id`)
)ENGINE = INNODB CHARSET="utf8" COLLATE="utf8_general_ci";