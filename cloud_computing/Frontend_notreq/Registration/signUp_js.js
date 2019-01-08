function formValidation()
{
var userId = document.signUp.userid;
var passwId = document.signUp.passwId;
var fName = document.signUp.firstNname;
var lName = document.signUp.lastNname;
var uemail = document.signUp.email;

if(userId_valid(userId,5,12))
	{
	if(passwId_valid(passwId,7,12))
		{
		if(allLetter(fName))
			{
			if(allLetter(lName))
				{	
				if(ValidateEmail(uemail))
					{
					alert("all the required details have been filled correctly");
					return true;
					}  
				}
			}			
		}
	}
return false;
}

function userId_valid(userId,min,max)
{
	var userId_len = userId.value.length;
	if (userId_len == 0)
	{
		alert("User Id should not be empty");
		userId.focus();
		return false;
	} 

	else if (userId_len >= max || userId_len < min)
	{
		alert("User Id length should be between "+min+" to "+max);
		userId.focus();
		return false;
	}
	return true;
}


function passwId_valid(passwId,min,max)
{
	var passwId_len = passwId.value.length;
	if (passwId_len == 0 )
	{
		alert("Password should not be empty / length be between "+min+" to "+max);
		passwId.focus();
		return false;
	}
	else if(passwId_len >= max || passwId_len < min)
	{
		alert("Password should not be empty / length be between "+min+" to "+max);
		passwId.focus();
		return false;
	}
	return true;
}


function allLetter(uname)
{ 
	var letters = /^[A-Za-z]+$/;
	if(uname.value.match(letters))
	{
		return true;
	}
	else
	{
		alert('Please use alphabets for the '+ uname);
		uname.focus();
		return false;
	}
}

function ValidateEmail(uemail)
{
	var mailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
	if(uemail.value.match(mailformat))
	{
		return true;
	}
	else
	{
		alert("You have entered an invalid email address!");
		uemail.focus();
		return false;
	}
}

