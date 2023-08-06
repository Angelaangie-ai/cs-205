create table user (
  User_name         text NOT NULL       ,
  Password          text NOT NULL       ,
  Date_registrate   text NOT NULL       ,
  FName             text NOT NULL       ,
  LName             text NOT NULL       , 
  PRIMARY KEY (User_name)
);

create table prefs(
  Pref_id                 int  NOT NULL ,
  User_id                 text NOT NULL ,
  Anonymous_self          int  NOT NULL ,
  Skin                    text NOT NULL ,
  Water_type              text NOT NULL ,
  Tank_size               text NOT NULL ,
  Show_friends            int  NOT NULL ,
  Location                text          ,
  PRIMARY KEY (Pref_id)                 ,
  FOREIGN KEY (User_id) REFERENCES user(User_name)
);

create table achievements(
  User_id                 text NOT NULL,
  Achieve_id              text NOT NULL,
  Date                    text NOT NULL,
  PRIMARY KEY (Achieve_id)             ,
  FOREIGN KEY (User_id) REFERENCES user(User_name)
);

create table friends (
  Connection_id                      int  NOT NULL ,
  User_id                            text NOT NULL ,
  Friend_id                          text NOT NULL ,
  PRIMARY KEY (Connection_id)                      ,
  FOREIGN KEY (User_id)   REFERENCES user(User_name) ,
  FOREIGN KEY (Friend_id) REFERENCES user(User_name)
);

create table communicate(
  Message_id                int  NOT NULL UNIQUE    ,
  Sender_id                 text NOT NULL           ,
  Reciever_id               text NOT NULL           ,
  Time                      text NOT NULL           ,
  Message                   text NOT NULL           ,
  PRIMARY KEY (Message_id)                          ,
  FOREIGN KEY (Sender_id)   REFERENCES user(User_name),
  FOREIGN KEY (Reciever_id) REFERENCES user(User_name)
);

create table trade (
  Trade_id              int  NOT NULL UNIQUE           ,
  Item                  text NOT NULL                  ,
  Price                 text NOT NULL                  ,
  Trader_id             text NOT NULL                  ,
  Offer_id              text NOT NULL                  ,
  Post_id               int  NOT NULL                  ,
  Chat_id               int  NOT NULL                  ,
  PRIMARY KEY (Trade_id)                               ,
  FOREIGN KEY (Trader_id) REFERENCES user(User_name)   ,
  FOREIGN KEY (Offer_id)  REFERENCES user(User_name)    ,
  FOREIGN KEY (Post_id)   REFERENCES post_manip(Post_id) ,
  FOREIGN KEY (Chat_id)   REFERENCES communicate(Message_id)
);

create table post_manip(
  Post_id               int  NOT NULL UNIQUE      ,
  User_id               text NOT NULL             , 
  Date                  text NOT NULL             ,
  Title                 text NOT NULL             ,  
  Contents              text NOT NULL             ,
  Small_T               int  NOT NULL             ,
  Big_T                 int  NOT NULL             ,
  Fresh_W               int  NOT NULL             ,
  Salt_W                int  NOT NULL             ,
  Trade                 int  NOT NULL             ,
  Education             int  NOT NULL             ,
  PRIMARY KEY (Post_id)                           ,
  FOREIGN KEY (User_id) REFERENCES user(User_name)
);

create table education_post(
  Resource_id                              int  NOT NULL,
  Post_id                                  int  NOT NULL,
  User_id                                  text NOT NULL,
  Topic                                    text NOT NULL,
  Link                                     text NOT NULL,
  PRIMARY KEY (Resource_id)                             ,
  FOREIGN KEY (User_id) REFERENCES user      (User_name),
  FOREIGN KEY (Post_id) REFERENCES post_manip(Post_id)  
);




.separator ","
.mode csv

.import "user.csv"              user
.import "prefs.csv"             prefs
.import "achievements.csv"      achievements
.import "friends.csv"           friends
.import "communicate.csv"       communicate
.import "trade.csv"             trade
.import "post_manip.csv"        post_manip
.import "education_post.csv"    education_post