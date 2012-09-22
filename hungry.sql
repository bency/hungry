Field	Type	Null	Key	Default	Extra
id	int(11)	NO	PRI	NULL	auto_increment
name	varchar(255)	YES		NULL	
address	varchar(255)	YES		NULL	
phone	varchar(255)	YES		NULL	
storetype	varchar(20)	NO			
week_order	varchar(255)	YES		NULL	
month_order	varchar(255)	YES		NULL	
total_order	varchar(255)	YES		NULL	
delivery	int(11)	YES		NULL	
condition_limit	varchar(255)	YES		NULL	
update_date	varchar(255)	YES		NULL	
condition2	varchar(10)	YES		NULL	
Field	Type	Null	Key	Default	Extra
id	int(11)	NO	PRI	NULL	auto_increment
storeid	int(11)	NO		1	
name	varchar(100)	NO		NULL	
price	int(11)	NO		NULL	
week_order	int(11)	YES		NULL	
month_order	int(11)	YES		NULL	
update_date	varchar(255)	YES		NULL	
