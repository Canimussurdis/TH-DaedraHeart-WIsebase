CREATE TABLE "users" (
  "user_id" SERIAL PRIMARY KEY,
  "name" varchar(100) UNIQUE NOT NULL,
  "password" varchar(20) NOT NULL,
  "mail" varchar(50),
  "birth_date" date,
  "sex" varchar(10)
);

CREATE TABLE "posts" (
  "post_id" SERIAL PRIMARY KEY,
  "title" varchar(100),
  "content" text,
  "pub_date" date DEFAULT CURRENT_DATE,
  "user_id" int NOT NULL,
  "rating" int DEFAULT 0
);

CREATE TABLE "images" (
  "image_id" SERIAL PRIMARY KEY,
  "extension" varchar(10) NOT NULL,
  "image_path" varchar(100) UNIQUE NOT NULL,
  "size" int,
  "height" int,
  "width" int
);

CREATE TABLE "posts_images" (
  "post_id" int,
  "image_id" int,
  PRIMARY KEY ("post_id", "image_id")
);

CREATE TABLE "grades" (
  "grade_id" SERIAL PRIMARY KEY,
  "grade_value" int check (grade_value = -1 or grade_value = 1),
  "post_id" int,
  "user_id" int
);

CREATE TABLE "comments" (
  "comment_id" SERIAL PRIMARY KEY,
  "content" text,
  "post_id" int,
  "user_id" int
);

ALTER TABLE "posts" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id") ON DELETE CASCADE;

ALTER TABLE "posts_images" ADD FOREIGN KEY ("image_id") REFERENCES "images" ("image_id") ON DELETE CASCADE;

ALTER TABLE "posts_images" ADD FOREIGN KEY ("post_id") REFERENCES "posts" ("post_id") ON DELETE CASCADE;

ALTER TABLE "grades" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id") ON DELETE CASCADE;

ALTER TABLE "grades" ADD FOREIGN KEY ("post_id") REFERENCES "posts" ("post_id") ON DELETE CASCADE;

ALTER TABLE "comments" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id") ON DELETE CASCADE;

ALTER TABLE "comments" ADD FOREIGN KEY ("post_id") REFERENCES "posts" ("post_id") ON DELETE CASCADE;
