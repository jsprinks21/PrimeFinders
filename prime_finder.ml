let find = int_of_string Sys.argv.(1);;
let found = 0;;
let lc = 0;;
let curr = 2;;
let primes = [];;

let rec print_int_list l lc = match l with
	| [] -> ()
	| hd::tl ->
		if (lc < 14) then
			(print_int hd ; print_string " " ; print_int_list tl (lc+1))
		else
			(print_int hd ; print_string " \n" ; print_int_list tl 0)
			
let find_primes tofind =
	let rec search found find curr primes = match (found < find) with
		| true ->
			let rec factors l i index lim =
				if (index < lim) then
					match l with
						| [] -> false
						| hd::tl ->
						  	if ((curr / hd) < hd) then
							   false
							else if (i mod hd = 0) then
								true
							else
								factors tl i (index+1) lim
				else
					false
			in
			if (factors primes curr 0 found) then
				search found find (curr+1) primes
			else
				search (found+1) find (curr+1) (primes@[curr])
		| false -> primes
	in
	print_int_list (search 0 tofind 2 []) 0;;

find_primes find;;
print_string("\n");;