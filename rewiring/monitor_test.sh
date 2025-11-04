#!/bin/bash
# Monitor the large test progress

echo "📊 Monitoring large_test_seed0"
echo "=============================="
echo ""

while ps aux | grep -q "[l]arge_test_seed0"; do
    cycles=$(ls -1d large_test_seed0/cycle_* 2>/dev/null | wc -l)
    bugs=$(ls -1d large_test_seed0/bugs/tribug_* 2>/dev/null | wc -l)
    timestamp=$(date +"%H:%M:%S")
    
    # Get last log line
    last_line=$(tail -1 large_test_seed0.log 2>/dev/null | head -c 100)
    
    printf "\r[%s] Progress: %2d/50 cycles | Bugs: %d | %s" "$timestamp" "$cycles" "$bugs" "$last_line"
    sleep 10
done

echo ""
echo ""
echo "✅ Test Complete!"
echo ""

# Show summary
if [ -f large_test_seed0/bug_summary.json ]; then
    echo "Summary:"
    cat large_test_seed0/bug_summary.json | python3 -m json.tool 2>/dev/null || cat large_test_seed0/bug_summary.json
else
    tail -20 large_test_seed0.log
fi

