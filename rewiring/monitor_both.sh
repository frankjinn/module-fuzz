#!/bin/bash
# Monitor both parallel tests

echo "📊 Monitoring Both Triple Simulator Tests"
echo "=========================================="
echo ""
echo "Test 1: 20 mutations/cycle → large_test_seed0/"
echo "Test 2: 50 mutations/cycle → large_test_seed0_50mut/"
echo ""

while ps aux | grep -q "[p]ython.*large_test_seed0"; do
    # Test 1 stats
    cycles1=$(ls -1d large_test_seed0/cycle_* 2>/dev/null | wc -l)
    bugs1=$(find large_test_seed0/bugs -name "tribug_*" -type d 2>/dev/null | wc -l)
    
    # Test 2 stats
    cycles2=$(ls -1d large_test_seed0_50mut/cycle_* 2>/dev/null | wc -l)
    bugs2=$(find large_test_seed0_50mut/bugs -name "tribug_*" -type d 2>/dev/null | wc -l)
    
    timestamp=$(date +"%H:%M:%S")
    
    printf "\r[%s] Test1: %2d/50 cycles (%d bugs) | Test2: %2d/50 cycles (%d bugs)" \
        "$timestamp" "$cycles1" "$bugs1" "$cycles2" "$bugs2"
    
    sleep 15
done

echo ""
echo ""
echo "✅ Tests Complete!"
echo ""

# Show summaries
echo "Test 1 Summary (20 mut/cycle):"
echo "------------------------------"
if [ -f large_test_seed0.log ]; then
    tail -20 large_test_seed0.log | grep -E "Summary|Bugs|cycles"
fi

echo ""
echo "Test 2 Summary (50 mut/cycle):"
echo "------------------------------"
if [ -f large_test_seed0_50mut.log ]; then
    tail -20 large_test_seed0_50mut.log | grep -E "Summary|Bugs|cycles"
fi

