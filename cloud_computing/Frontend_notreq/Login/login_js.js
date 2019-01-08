function formValidation()
{
var userId = document.Login.userid;
var passwId = document.Login.passwId;

if(userId_valid(userId,5,12))
	{
	if(passwId_valid(passwId,7,12))
		{
			alert("all the required details have been filled correctly");
			return true;				
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

