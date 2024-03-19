Jarod Spencer CS490

After unzipping the .gz files to .bed, run the bedtools command
bedtools getfasta -fi path_to_ref/hg38.fa -bed <path_to_narrowBed> -fo <output_path/output#.txt>
With # being replaced by a non-zero int.
You need to create a file called output#.txt, length#.txt, avg#.txt, and final#.txt once again with # being replaced by a non-zero int.
Then you need to launch lengthFinder, avgFinder, and sort in that order.
When you launch them, you need to follow up with the commands -a # with the # being the number you assigned to the .txt files.

lengthFinder will take the output#.txt file, take the numbers of every other line and output those to length#.txt.
avgFinder will take length#.txt and simply output the average number to avg#.txt.
Finally, sort will take the data from output#.txt and the average number from avg#.txt and output lines that are equal to or exceed the average length to final#.txt to equal the average.

All of the finilized sorted data can be found in the final#.txt files. 
