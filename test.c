c2r4p12% ./run 8 32 25 53 17 9 6 28 42 36 18 23 20 48 21 12 56 55 10 5 50 26 54 44 60 30 45 47 57 52                          
pb
ra
ra
ra
pb
pb
pb
ra
ra
ra
pb
ra
pb
ra
pb
pb
ra
ra
pb
pb
ra
pb
ra
pb
ra
pb
pb
ra
ra
ra
pb
pb
ra
pb
pb
pb
pb
pb
pb
pb
pb
pb
pb
pb
pb
pb
pb
-----> cost_cur 1, target_cur: 0, stack_b->arr[0] 25
-----> cost_cur 1, target_cur: 0, stack_b->arr[1] 24
-----> cost_cur 2, target_cur: 0, stack_b->arr[2] 29
-----> cost_cur 3, target_cur: 0, stack_b->arr[3] 21
-----> cost_cur 4, target_cur: 0, stack_b->arr[4] 30
-----> cost_cur 5, target_cur: 0, stack_b->arr[5] 26
-----> cost_cur 6, target_cur: 0, stack_b->arr[6] 23
-----> cost_cur 7, target_cur: 0, stack_b->arr[7] 27
-----> cost_cur 8, target_cur: 0, stack_b->arr[8] 28
-----> cost_cur 9, target_cur: 0, stack_b->arr[9] 22
cost_min: 1; target_a: 0, target_b: 0 stack_b->arr[target_b]: 25
pa
stack A: 25
-----> cost_cur 0, target_cur: 0, stack_b->arr[0] 24
-----> cost_cur 1, target_cur: 1, stack_b->arr[1] 29
-----> cost_cur 2, target_cur: 0, stack_b->arr[2] 21
-----> cost_cur 3, target_cur: 1, stack_b->arr[3] 30
-----> cost_cur 4, target_cur: 1, stack_b->arr[4] 26
-----> cost_cur 5, target_cur: 0, stack_b->arr[5] 23
-----> cost_cur 6, target_cur: 1, stack_b->arr[6] 27
-----> cost_cur 7, target_cur: 1, stack_b->arr[7] 28
-----> cost_cur 8, target_cur: 0, stack_b->arr[8] 22
cost_min: 0; target_a: 0, target_b: 0 stack_b->arr[target_b]: 24
pa
stack A: 24
stack A: 25
-----> cost_cur 1, target_cur: 2, stack_b->arr[0] 29
-----> cost_cur 1, target_cur: 0, stack_b->arr[1] 21
-----> cost_cur 2, target_cur: 2, stack_b->arr[2] 30
-----> cost_cur 3, target_cur: 2, stack_b->arr[3] 26
-----> cost_cur 4, target_cur: 0, stack_b->arr[4] 23
-----> cost_cur 5, target_cur: 2, stack_b->arr[5] 27
-----> cost_cur 6, target_cur: 2, stack_b->arr[6] 28
-----> cost_cur 7, target_cur: 0, stack_b->arr[7] 22
cost_min: 1; target_a: 2, target_b: 0 stack_b->arr[target_b]: 29
pa
ra
stack A: 24
stack A: 25
stack A: 29
-----> cost_cur 0, target_cur: 0, stack_b->arr[0] 21
-----> cost_cur 1, target_cur: 3, stack_b->arr[1] 30
-----> cost_cur 4, target_cur: 2, stack_b->arr[2] 26
-----> cost_cur 3, target_cur: 0, stack_b->arr[3] 23
-----> cost_cur 6, target_cur: 2, stack_b->arr[4] 27
-----> cost_cur 7, target_cur: 2, stack_b->arr[5] 28
-----> cost_cur 6, target_cur: 0, stack_b->arr[6] 22
cost_min: 0; target_a: 0, target_b: 0 stack_b->arr[target_b]: 21
pa
stack A: 21
stack A: 24
stack A: 25
stack A: 29
-----> cost_cur 1, target_cur: 4, stack_b->arr[0] 30
-----> cost_cur 3, target_cur: 3, stack_b->arr[1] 26
-----> cost_cur 2, target_cur: 1, stack_b->arr[2] 23
-----> cost_cur 5, target_cur: 3, stack_b->arr[3] 27
-----> cost_cur 6, target_cur: 3, stack_b->arr[4] 28
-----> cost_cur 5, target_cur: 1, stack_b->arr[5] 22
cost_min: 1; target_a: 4, target_b: 0 stack_b->arr[target_b]: 30
pa
ra
stack A: 21
stack A: 24
stack A: 25
stack A: 29
stack A: 30
-----> cost_cur 4, target_cur: 3, stack_b->arr[0] 26
-----> cost_cur 2, target_cur: 1, stack_b->arr[1] 23
-----> cost_cur 6, target_cur: 3, stack_b->arr[2] 27
-----> cost_cur 7, target_cur: 3, stack_b->arr[3] 28
-----> cost_cur 4, target_cur: 1, stack_b->arr[4] 22
cost_min: 2; target_a: 1, target_b: 1 stack_b->arr[target_b]: 23
rr
pa
rra
stack A: 21
stack A: 23
stack A: 24
stack A: 25
stack A: 29
stack A: 30
-----> cost_cur 4, target_cur: 4, stack_b->arr[0] 27
-----> cost_cur 5, target_cur: 4, stack_b->arr[1] 28
-----> cost_cur 2, target_cur: 1, stack_b->arr[2] 22
-----> cost_cur 4, target_cur: 4, stack_b->arr[23] 26
cost_min: 2; target_a: 1, target_b: 2 stack_b->arr[target_b]: 22
rr
rb
pa
rra
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 25
stack A: 29
stack A: 30
-----> cost_cur 4, target_cur: 5, stack_b->arr[20] 26
-----> cost_cur 4, target_cur: 5, stack_b->arr[21] 27
-----> cost_cur 4, target_cur: 5, stack_b->arr[22] 28
cost_min: 4; target_a: 5, target_b: 20 stack_b->arr[target_b]: 26
rrr
rrr
rb
pa
ra
ra
ra
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 25
stack A: 28
stack A: 29
stack A: 30
-----> cost_cur 6, target_cur: 5, stack_b->arr[20] 26
-----> cost_cur 6, target_cur: 5, stack_b->arr[21] 27
cost_min: 6; target_a: 5, target_b: 20 stack_b->arr[target_b]: 26
rrr
rrr
ra
pa
ra
ra
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
-----> cost_cur 8, target_cur: 5, stack_b->arr[0] 27
cost_min: 8; target_a: 5, target_b: 0 stack_b->arr[target_b]: 27
ra
ra
ra
ra
pa
rra
rra
rra
rra
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
cost_min: 2147483647; target_a: 0, target_b: 0 stack_b->arr[target_b]: 11
pa
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
cost_min: 2147483647; target_a: 0, target_b: 0 stack_b->arr[target_b]: 17
pa
ra
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
cost_min: 2147483647; target_a: 0, target_b: 0 stack_b->arr[target_b]: 18
pa
ra
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
cost_min: 2147483647; target_a: 0, target_b: 0 stack_b->arr[target_b]: 14
pa
ra
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
cost_min: 2147483647; target_a: 0, target_b: 0 stack_b->arr[target_b]: 12
pa
ra
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
cost_min: 2147483647; target_a: 0, target_b: 0 stack_b->arr[target_b]: 16
pa
ra
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
cost_min: 2147483647; target_a: 0, target_b: 0 stack_b->arr[target_b]: 20
pa
ra
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
cost_min: 2147483647; target_a: 0, target_b: 0 stack_b->arr[target_b]: 15
pa
ra
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
cost_min: 2147483647; target_a: 0, target_b: 0 stack_b->arr[target_b]: 19
pa
ra
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
cost_min: 2147483647; target_a: 0, target_b: 0 stack_b->arr[target_b]: 13
pa
ra
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
-----> cost_cur 0, target_cur: 0, stack_b->arr[0] 1
-----> cost_cur 1, target_cur: 0, stack_b->arr[1] 5
-----> cost_cur 2, target_cur: 0, stack_b->arr[2] 6
-----> cost_cur 3, target_cur: 0, stack_b->arr[3] 10
-----> cost_cur 4, target_cur: 0, stack_b->arr[4] 9
-----> cost_cur 5, target_cur: 0, stack_b->arr[5] 8
-----> cost_cur 4, target_cur: 0, stack_b->arr[6] 2
-----> cost_cur 3, target_cur: 0, stack_b->arr[7] 4
-----> cost_cur 2, target_cur: 0, stack_b->arr[8] 7
-----> cost_cur 1, target_cur: 0, stack_b->arr[9] 3
cost_min: 0; target_a: 0, target_b: 0 stack_b->arr[target_b]: 1
pa
stack A: 1
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
-----> cost_cur 2, target_cur: 1, stack_b->arr[0] 5
-----> cost_cur 2, target_cur: 1, stack_b->arr[1] 6
-----> cost_cur 2, target_cur: 1, stack_b->arr[2] 10
-----> cost_cur 3, target_cur: 1, stack_b->arr[3] 9
-----> cost_cur 4, target_cur: 1, stack_b->arr[4] 8
-----> cost_cur 6, target_cur: 1, stack_b->arr[5] 2
-----> cost_cur 5, target_cur: 1, stack_b->arr[6] 4
-----> cost_cur 4, target_cur: 1, stack_b->arr[7] 7
-----> cost_cur 3, target_cur: 1, stack_b->arr[8] 3
cost_min: 2; target_a: 1, target_b: 0 stack_b->arr[target_b]: 5
ra
pa
rra
stack A: 1
stack A: 5
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
-----> cost_cur 4, target_cur: 2, stack_b->arr[0] 6
-----> cost_cur 4, target_cur: 2, stack_b->arr[1] 10
-----> cost_cur 4, target_cur: 2, stack_b->arr[2] 9
-----> cost_cur 4, target_cur: 2, stack_b->arr[3] 8
-----> cost_cur 4, target_cur: 1, stack_b->arr[4] 2
-----> cost_cur 5, target_cur: 1, stack_b->arr[5] 4
-----> cost_cur 6, target_cur: 2, stack_b->arr[6] 7
-----> cost_cur 3, target_cur: 1, stack_b->arr[7] 3
cost_min: 3; target_a: 1, target_b: 7 stack_b->arr[target_b]: 3
ra
rb
pa
rra
stack A: 1
stack A: 10
stack A: 5
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
-----> cost_cur 2, target_cur: 1, stack_b->arr[0] 9
-----> cost_cur 2, target_cur: 1, stack_b->arr[1] 8
-----> cost_cur 2, target_cur: 1, stack_b->arr[2] 2
-----> cost_cur 3, target_cur: 1, stack_b->arr[3] 4
-----> cost_cur 5, target_cur: 1, stack_b->arr[4] 7
-----> cost_cur 4, target_cur: 1, stack_b->arr[5] 3
-----> cost_cur 3, target_cur: 1, stack_b->arr[6] 6
cost_min: 2; target_a: 1, target_b: 0 stack_b->arr[target_b]: 9
ra
pa
rra
stack A: 1
stack A: 9
stack A: 10
stack A: 5
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
-----> cost_cur 2, target_cur: 1, stack_b->arr[0] 8
-----> cost_cur 2, target_cur: 1, stack_b->arr[1] 2
-----> cost_cur 2, target_cur: 1, stack_b->arr[2] 4
-----> cost_cur 3, target_cur: 1, stack_b->arr[3] 7
-----> cost_cur 4, target_cur: 1, stack_b->arr[4] 3
-----> cost_cur 3, target_cur: 1, stack_b->arr[5] 6
cost_min: 2; target_a: 1, target_b: 0 stack_b->arr[target_b]: 8
ra
pa
rra
stack A: 1
stack A: 8
stack A: 9
stack A: 10
stack A: 5
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
-----> cost_cur 2, target_cur: 1, stack_b->arr[0] 2
-----> cost_cur 2, target_cur: 1, stack_b->arr[1] 4
-----> cost_cur 2, target_cur: 1, stack_b->arr[2] 7
-----> cost_cur 4, target_cur: 1, stack_b->arr[3] 3
-----> cost_cur 3, target_cur: 1, stack_b->arr[4] 6
cost_min: 2; target_a: 1, target_b: 0 stack_b->arr[target_b]: 2
ra
pa
rra
stack A: 1
stack A: 2
stack A: 8
stack A: 9
stack A: 10
stack A: 5
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
-----> cost_cur 4, target_cur: 2, stack_b->arr[0] 4
-----> cost_cur 4, target_cur: 2, stack_b->arr[1] 7
-----> cost_cur 4, target_cur: 2, stack_b->arr[2] 3
-----> cost_cur 5, target_cur: 2, stack_b->arr[3] 6
cost_min: 4; target_a: 2, target_b: 0 stack_b->arr[target_b]: 4
ra
ra
pa
rra
rra
stack A: 1
stack A: 2
stack A: 4
stack A: 8
stack A: 9
stack A: 10
stack A: 5
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
-----> cost_cur 6, target_cur: 3, stack_b->arr[0] 7
-----> cost_cur 4, target_cur: 2, stack_b->arr[1] 3
-----> cost_cur 7, target_cur: 3, stack_b->arr[2] 6
cost_min: 4; target_a: 2, target_b: 1 stack_b->arr[target_b]: 3
rr
ra
pa
rra
rra
stack A: 1
stack A: 2
stack A: 3
stack A: 4
stack A: 8
stack A: 9
stack A: 10
stack A: 5
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
-----> cost_cur 8, target_cur: 4, stack_b->arr[0] 6
-----> cost_cur 8, target_cur: 4, stack_b->arr[1] 7
cost_min: 8; target_a: 4, target_b: 0 stack_b->arr[target_b]: 6
ra
ra
ra
ra
pa
rra
rra
rra
rra
stack A: 1
stack A: 2
stack A: 3
stack A: 4
stack A: 6
stack A: 8
stack A: 9
stack A: 10
stack A: 5
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
-----> cost_cur 10, target_cur: 5, stack_b->arr[0] 7
cost_min: 10; target_a: 5, target_b: 0 stack_b->arr[target_b]: 7
ra
ra
ra
ra
ra
pa
rra
rra
rra
rra
rra
stack A: 1
stack A: 2
stack A: 3
stack A: 4
stack A: 6
stack A: 7
stack A: 8
stack A: 9
stack A: 10
stack A: 5
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
cost_min: 2147483647; target_a: 0, target_b: 0 stack_b->arr[target_b]: 0
pa
stack A: 0
stack A: 1
stack A: 2
stack A: 3
stack A: 4
stack A: 6
stack A: 7
stack A: 8
stack A: 9
stack A: 10
stack A: 5
stack A: 11
stack A: 21
stack A: 22
stack A: 23
stack A: 24
stack A: 27
stack A: 25
stack A: 28
stack A: 29
stack A: 26
stack A: 30
stack A: 17
stack A: 18
stack A: 14
stack A: 12
stack A: 16
stack A: 20
stack A: 15
stack A: 19
stack A: 13
