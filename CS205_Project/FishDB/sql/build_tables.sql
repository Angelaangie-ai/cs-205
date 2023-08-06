create table breed (
  Breed_id         int NOT NULL UNIQUE ,
  Size             int NOT NULL        ,
  Color            text NOT NULL UNIQUE, 
  Location         text NOT NULL       ,
  PRIMARY KEY (Breed_id)
);

create table fish(
  Fish_id                 int NOT NULL UNIQUE ,
  Breed_id                int NOT NULL        ,
  Name                    text NOT NULL       ,
  Science_name            text NOT NULL       ,
  PRIMARY KEY (Fish_id)                       ,
  FOREIGN KEY (Breed_id) REFERENCES breed(Breed_id)
);

create table classification(
  Class_id                 int NOT NULL UNIQUE,
  Fish_id                  int NOT NULL       ,
  Rank                     text NOT NULL      ,
  Family                   text NOT NULL      ,
  Class                    text NOT NULL      ,
  PRIMARY KEY (Class_id)                      ,
  FOREIGN KEY (Fish_id) REFERENCES fish(Fish_id)
);

create table diet (
  Diet_id                      int NOT NULL UNIQUE ,
  Breed_id                     int NOT NULL        ,
  Diet                         text NOT NULL       ,
  PRIMARY KEY (Diet_id)                            ,
  FOREIGN KEY (Breed_id) REFERENCES breed(Breed_id),
);

create table conservation(
  Conserve_id                int NOT NULL UNIQUE    ,
  Breed_id                   int NOT NULL           ,
  Population                 int NOT NULL           ,
  Status                     text NOT NULL          ,
  PRIMARY KEY (Conserve_id)                         ,
  FOREIGN KEY (Breed_id) REFERENCES breed(Breed_id) ,
);




.separator ","
.mode csv

.import "data/workson.csv"       workson
.import "data/project.csv"       project
.import "data/employee.csv"      employee
.import "data/deptlocations.csv" deptlocations
.import "data/dependent.csv"     dependent
.import "data/department.csv"    department