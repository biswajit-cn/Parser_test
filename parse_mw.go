package parse_test

import (
	"fmt"

	"github.com/pingcap/parser"
	"github.com/pingcap/parser/ast"
	_ "github.com/pingcap/parser/test_driver"
)

func Parse(sql string) {
	astNode, err := parse(sql)
	if err != nil {
		fmt.Printf("parse error: %v\n", err.Error())
	}
	fmt.Printf("%v\n", *astNode)
}
func parse(sql string) (*ast.StmtNode, error) {
	p := parser.New()

	stmtNodes, _, err := p.Parse(sql, "", "")
	if err != nil {
		return nil, err
	}

	return &stmtNodes[0], nil
}

// func main() {
// 	astNode, err := parse("SELECT a, b FROM t")
// 	if err != nil {
// 		fmt.Printf("parse error: %v\n", err.Error())
// 		return
// 	}
// 	fmt.Printf("%v\n", *astNode)
// }
