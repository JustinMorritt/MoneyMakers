Hash notes 


660 get primes ,   2 * 2 * 3* 5 *11

build an array of the first 13 primes ...
1,2,3,5,7,11,13,17,19,23,29,31,37 ---if all suits ..multiply by next prime 41 

-hash value .. take some sort of value , run through algo .. come up with number
-pip value of 5 cards and come up with combination.
-3H , 3S, 4D , 5c , 7D
  2    2   3   5    11     PIP value == 660
  
  AH AS AC AD KD  == 37*37*37*37*31 
  
  
  A , K , Q , J , T  == 37*31*29*23*19 = 14 535 931
  K , Q, j, T, 9,	 == 31*29*23 *19*17 =  6 678 671 
  Q, J, T, 9, 8		 ==                          2 800 753
  .
  .
  \/
  5,4,3,2,A  ==                     lowest priority.. = 1 110
  
  
  first run through disregaurding the suit..
  9 diff straights.. 
  build big static map .
  value and rank
  
  store the name as the following   std::map<unsigned , std::pair<unsigned, std::string>>
											hash#                 rank          name
											
	
	build vectors of the combinations .
	end with high cards :P
  
  