cd "/Users/filippersson/Desktop/DOA/Labbar/LABB3/plot"
datafile = 'sequential_search.txt'
set  title "Sequential search -- Prime series"
set xrange [0:20000]
set terminal png size 800,600
set output 'sequential_search.png'
set xlabel "N elements"
set ylabel "t [{/ Symbol m } s]"
set key autotitle columnhead
f2(x) = a2 * x + b2
fit f2(x) datafile index 0 using 1:2 via a2,b2
plot datafile \
    index 0 \
    using 1:2:3 \
    with errorbars\
    title "Prime integers" , f2(x) title "O(n)"
set output
set terminal pop

cd "/Users/filippersson/Desktop/DOA/Labbar/LABB3/plot"
datafile = 'binary_search.txt'
set  title "Binary search -- Prime series"
set xrange [0:20000]
set terminal png size 800,600
set output 'binary_search.png'
set xlabel "N elements"
set ylabel "t [{/ Symbol m } s]"
set key autotitle columnhead
f4(x) = a4 * (log(x)) + b4
fit f4(x) datafile index 0 using 1:2 via a4,b4
plot datafile \
    index 0 \
    using 1:2:3 \
    with errorbars\
    title "Prime integers" , f4(x) title "O(log(n))"
set output
set terminal pop

cd "/Users/filippersson/Desktop/DOA/Labbar/LABB3/plot"
datafile = 'binary_tree_search.txt'
set  title "Binary tree search -- Prime series"
set terminal png size 800,600
set xrange [0:20000]
set yrange [0:0.0000003]
set output 'binary_tree_search.png'
set xlabel "N elements"
set ylabel "t [{/ Symbol m } s]"
set key autotitle columnhead
f3(x) = a3 * (log(x))
fit f3(x) datafile index 0 using 1:2 via a3
plot datafile \
    index 0 \
    using 1:2:3 \
    with errorbars\
    title "Prime integers" , f3(x) title "O(log(n))"
set output
set terminal pop

cd "/Users/filippersson/Desktop/DOA/Labbar/LABB3/plot"
datafile = 'hash_table_search.txt'
set  title "Hash table -- Prime series"
set terminal png size 800,600
set output 'hash_table_search.png'
set xlabel "N elements"
set ylabel "t [{/ Symbol m } s]"
set yrange [0:0.0000001]
set xrange [0:20000]
set key autotitle columnhead
f1(x) = a1
fit f1(x) datafile index 0 using 1:2 via a1
plot datafile \
    index 0 \
    using 1:2:3 \
    with errorbars\
    title "Prime integers" , f1(x) title "O(1)"
set output
set terminal pop
