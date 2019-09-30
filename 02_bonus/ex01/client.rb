# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    client.rb                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 11:47:54 by kmira             #+#    #+#              #
#    Updated: 2019/09/07 15:14:32 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#single line Comment
=begin
	Multiple Line Comment
	Is done like this
=end

#to run a ruby file use 'ruby <filename.rb>'

#The 'require' keyword is like the 'include' keyword in C/C++
require "oauth2"
UID = ENV['CERYNEIAN_HIND_UID']
SECRET = ENV['CERYNEIAN_HIND_SECRET']

=begin
	returns a new Client object/class.
	This is done by using the OAuth and 'bringing out' Client.new method
	The keyword to make inside methods external is the operator '::'
=end
client = OAuth2::Client.new(UID, SECRET, site: "https://api.intra.42.fr")

#within the Client instance <client> in the client_credentials to retrieve the token using the get_token method
token = client.client_credentials.get_token

=begin
	using the token to do a parsed version of the ("/v2/user/<intra>/locations") with the #parsed method to get an 'array'
	of login times. From that we search the string for the (first?) occurance of "end_at" and if it is 'nil' (meaning the user is
	currently logged in) we puts.
=end
if (ARGV.length == 0)
	puts "No arguement supplied. Cannot get corresponding file."
	exit
elsif (ARGV.length > 1)
	puts "Next time please only give us one arguement. Just this one time and for you we will run the program with the first arguement."
end

begin
	if (File.extname(ARGV[0]) == ".txt")
		intra_names = File.open(ARGV[0], "r").each do |name|
			intra = name.chomp("\n")
			begin
				message = token.get("/v2/users/#{intra}/locations")
				while (message.status == 500)
					puts "Was not sucessful, going to retry in 1 second."
					sleep(3)
					puts "Retrying"
					message = token.get("/v2/users/#{intra}/locations")
				end
				if (message.parsed[0]["end_at"])
					puts "#{intra} is not logged in."
				else
					puts "#{intra} is on computer: " + message.parsed[0]["host"]
				end
			rescue
				puts "🚨Invalid username 🚨"
			end
		end
		intra_names.close
	else
		puts "File is not a .txt file! Why you do dis?"
	end
rescue
	puts "File does not exist! What is wrong with you?"
end
