#!/usr/bin/perl -w
#Written by Constantinos Paraskevopoulos in February 2016
#Checks the format of code provided as arguments

die "Usage: $0 <indentation> <files>\n" if !defined $ARGV[0];
die "$0: indentation must be a non-negative integer\n" if $ARGV[0] !~ /^[0-9]+$/;

for $file (@ARGV[1..$#ARGV]) {
	open FILE, '<', $file or print "$0: Cannot open '$file': $!\n" and next;
	@lines = <FILE>;

	#checks format of each line in the current file
	for $i (0..$#lines) {
		chomp $lines[$i];
		$line_number = $i + 1;

		#detects lines with trailing whitespace
		if ($lines[$i] =~ /\s+$/) {
			print "Found trailing whitespace on line $line_number of $file\n";
		}

		#detects lines where leading whitespace is not a multiple of $ARGV[0]
		if ($lines[$i] =~ /^(\s+)/) {
			if (length($1) % $ARGV[0] != 0) {
				print "Found inconsistent leading whitespace on line $line_number of $file\n" 
			}
		}

		#detects double blank lines
		if ($i != $#lines && $lines[$i] =~ /^\s*$/ && $lines[$i + 1] =~ /^\s*$/) {
			print "Found double blank lines at line $line_number of $file\n";
		}

	}

	close FILE;
}
