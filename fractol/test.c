	else if (*str == '-' || *str == '+')
		{
            sign_count++;
            if (sign_count > 1 || !numeric_flag) 
			{
                fd_putstr(ERROR_MESSAGE_1, STDERR_FILENO);
                exit(1);
            }
        } 