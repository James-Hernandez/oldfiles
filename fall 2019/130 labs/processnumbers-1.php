<?php

// Solution for the POST
// If there is no variable myarray in POST, we consider an array [0].
$myarray = (isset($_POST['myarray'])) ? $_POST['myarray'] : ['0'];

#

function NL() {
echo "<br>";
}

function ArrayRand($n) {
	// create an array of size n
	$some_data=0;
	$array = array_fill(0,$n,$some_data);
	for ($i=2;$i<$n;$i++) { // first 2 elements are 0
	$array[$i]=rand(0,1000);
	}
	return $array;
}

function ArraySortedRand($n) {
	// create an array of size n
	$some_data=0;
	$array = array_fill(0,$n,$some_data);
	$array[0]=rand(0,10);
	for ($i=1;$i<$n;$i++) {
		$array[$i]=$array[$i-1]+rand(0,10);
	}
return $array;
}

function DisplayArray($a) {
	for ($i=0;$i<count($a);$i++)
		echo $a[$i] .'_';
	NL();
}
 
function iterative_binary_search($x, $list) {
	$left = 0;
	$right = count($list)-1;
	while ($left <= $right) {
		$mid = ($left + $right) >> 1;
 
		if ($list[$mid] == $x) {
			return $mid;
		} elseif ($list[$mid] > $x) {
			$right = $mid - 1;
		} elseif ($list[$mid] < $x) {
			$left = $mid + 1;
		}
	}
	return -1;
}
 
function fibonacci($n) {
	if (( $n == 0 ) || ( $n == 1 )) {
     return $n;
	}
	return fibonacci( $n-2 ) + fibonacci( $n-1 );
}

function isPrime($num) {
    //1 is not prime
    if($num == 1)
        return false;
    //2 is prime (the only even number that is prime)
    if($num == 2)
        return true;
    //*if the number is divisible by two, then it's not prime and it's no longer needed to check other even numbers
    if($num % 2 == 0) {
        return false;
    }
    // Checks the odd numbers. If any of them is a factor, then it returns false.
    // The sqrt can be an aproximation, rounds it to the next highest integer value.
    $ceil = ceil(sqrt($num));
    for($i = 3; $i <= $ceil; $i = $i + 2) {
        if($num % $i == 0)
            return false;
    }
    return true;
}

function FindPrime($a) {
	$k=0;
	//$out=new Array();
	for ($i=0;$i<count($a);$i++) {
	if (isPrime($a[$i])) {
		    $out[$k]=$a[$i];
			$k=$k+1;
		}
	}
	return $out;
}

function Average($x) {	
	$a=0;
	for ($i=0;$i<sizeof($x);$i++)
		$a+=$x[$i];
	return $a/sizeof($x);
}

function StandardDeviation($x) {
    $a=Average($x);
	$s=0;
	for ($i=0;$i<sizeof($x);$i++)
		$s+= ($x[$i]-$a)**2;
	return  sqrt($s/sizeof($x));
}

function Median($x) {	
	$count = count($x);
    sort($x);
	$mid = floor(($count-1)/2);
	return $x[$mid];
}

function Maximum($x) {
	return max($x);
}

function Minimum($x) {
	return min($x);
}


$do_example=0;

if ($do_example) {
	// To verify the functions are working
	// It is a good practice to test your functions on the PHP side before you test them with incoming data from the client
	$list = array(0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 57, 90, 144);
	
	echo DisplayArray(ArrayRand(10));
	NL();
	echo DisplayArray(ArraySortedRand(10));
	NL();
	
	$x = 57; // element to search
	echo iterative_binary_search($x, $list);
	NL();
	$x = 19; // element to search
	echo iterative_binary_search($x, $list);
	NL();

	echo "List of Fibonacci <br>";
	for ($i=1;$i<=20;$i++) {	
		echo "Element ". $i . " with value ". fibonacci($i) ."<br>";
	}

	$a[0]=5;
	$a[1]=7;
	$a[2]=14;
	echo DisplayArray(FindPrime($a));
	echo DisplayArray(FindPrime(ArraySortedRand(500)));
}
else
{
	$myarray=json_decode($myarray);
	// You can verify that each element in the array is a number !
	
	$prime=FindPrime($myarray);	
	$array = ['average' => Average($myarray),
	  'standarddeviation' => StandardDeviation($myarray),
	  'median' => Median($myarray),
	  'max' => Maximum($myarray),
	  'min' => Minimum($myarray),
	  'prime' => FindPrime($myarray) ];		 		  
	echo json_encode($array);
}

?>