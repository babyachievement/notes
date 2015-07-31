#搜索和排序算子

A "search" operator entry indicates that an index of this operator family can be searched to find all rows satisfying WHERE indexed_column operator constant. Obviously, such an operator must return boolean, and its left-hand input type must match the index's column data type.

An "ordering" operator entry indicates that an index of this operator family can be scanned to return rows in the order represented by ORDER BY indexed_column operator constant. Such an operator could return any sortable data type, though again its left-hand input type must match the index's column data type. The exact semantics of the ORDER BY are specified by the amopsortfamily column, which must reference a B-tree operator family for the operator's result type.
