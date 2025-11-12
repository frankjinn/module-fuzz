# Bit Tracer - Format and Layout Options

## Script Location
```
/opt/module-fuzz/rewiring/scripts/trace_bit_bundled.py
```

## Command Line Options

### Required Parameters
- `--bit <NUMBER>` - The output bit to trace (e.g., 10, 24)
- `--top <FILE>` - Path to top.sv file
- `--modules <DIR>` - Module directory path

### Optional Parameters
- `--output <FILE>` - Output filename (default: trace_bundled.svg)
- `--format {matplotlib,dot}` - Output format (default: dot)
- `--layout {hierarchical,compact,both}` - Graph layout (default: hierarchical)

---

## Format Options

### 1. matplotlib (Old Format)
```bash
--format matplotlib
```

**Characteristics:**
- ✅ Original format with straight/orthogonal lines
- ✅ Hierarchical layout (inputs on left, outputs on right)
- ✅ Colored edges: blue for wires, orange for logic
- ✅ Detailed edge labels with expressions
- ✅ Legend showing node types
- ⚠️ **May hang on graphs >30 nodes**
- ⚠️ Slower rendering
- ⚠️ Only supports hierarchical layout

**Best for:**
- Small graphs (< 30 nodes)
- When you need the exact old visualization style
- Final publication-quality diagrams

**Example:**
```bash
python3 /opt/module-fuzz/rewiring/scripts/trace_bit_bundled.py \
    --bit 24 \
    --top /opt/module-fuzz/TestArchive/large_test1/bugs/tribug_1339297989_1762975525/top.sv \
    --modules /opt/module-fuzz/test_libraries/comprehensive_tests \
    --output trace_old_format.svg \
    --format matplotlib
```

---

### 2. dot (New Format - Recommended)
```bash
--format dot
```

**Characteristics:**
- ✅ Fast rendering, never hangs
- ✅ Works with large graphs (100+ nodes)
- ✅ Supports multiple layout options
- ✅ Generates editable DOT files
- ✅ Can export to PNG, PDF, etc.
- ✅ Colored nodes and edges
- ✅ Module names shown on nodes

**Best for:**
- Large graphs (30+ nodes)
- Quick iteration and debugging
- When you need multiple layout views
- Automated processing

**Example:**
```bash
python3 /opt/module-fuzz/rewiring/scripts/trace_bit_bundled.py \
    --bit 24 \
    --top /opt/module-fuzz/TestArchive/large_test1/bugs/tribug_1339297989_1762975525/top.sv \
    --modules /opt/module-fuzz/test_libraries/comprehensive_tests \
    --output trace_new_format.svg \
    --format dot \
    --layout hierarchical
```

---

## Layout Options (DOT format only)

### 1. hierarchical (Default)
```bash
--layout hierarchical
```

**Description:**
- All external inputs (green boxes) grouped on LEFT
- External output (pink box) on RIGHT
- Clear left-to-right data flow
- Easy to trace from inputs to output

**Output:** Single SVG with hierarchical layout

---

### 2. compact
```bash
--layout compact
```

**Description:**
- Free-form layout
- Auto-arranged for minimal edge crossings
- More compact for complex graphs
- Better for seeing module relationships

**Output:** Single SVG with compact layout

---

### 3. both (Recommended)
```bash
--layout both
```

**Description:**
- Generates BOTH hierarchical AND compact layouts
- Get two perspectives on the same trace
- Compare which layout is clearer

**Output:**
- `<basename>_hierarchical.svg`
- `<basename>_hierarchical.dot`
- `<basename>_compact.svg`
- `<basename>_compact.dot`

**Example:**
```bash
python3 /opt/module-fuzz/rewiring/scripts/trace_bit_bundled.py \
    --bit 24 \
    --top top.sv \
    --modules /opt/module-fuzz/test_libraries/comprehensive_tests \
    --output trace.svg \
    --format dot \
    --layout both

# Generates:
#   trace_hierarchical.svg
#   trace_hierarchical.dot
#   trace_compact.svg
#   trace_compact.dot
```

---

## Complete Examples

### Example 1: Old Format (matplotlib)
```bash
cd /opt/module-fuzz/TestArchive/large_test1/bugs/tribug_1339297989_1762975525

python3 /opt/module-fuzz/rewiring/scripts/trace_bit_bundled.py \
    --bit 10 \
    --top top.sv \
    --modules /opt/module-fuzz/test_libraries/comprehensive_tests \
    --output /opt/module-fuzz/trace_output/bit10_old.svg \
    --format matplotlib
```

### Example 2: New Format - Single Layout
```bash
cd /opt/module-fuzz/TestArchive/large_test1/bugs/tribug_1339297989_1762975525

python3 /opt/module-fuzz/rewiring/scripts/trace_bit_bundled.py \
    --bit 24 \
    --top top.sv \
    --modules /opt/module-fuzz/test_libraries/comprehensive_tests \
    --output /opt/module-fuzz/trace_output/bit24.svg \
    --format dot \
    --layout hierarchical
```

### Example 3: New Format - Both Layouts (Recommended)
```bash
cd /opt/module-fuzz/TestArchive/large_test1/bugs/tribug_1339297989_1762975525

python3 /opt/module-fuzz/rewiring/scripts/trace_bit_bundled.py \
    --bit 24 \
    --top top.sv \
    --modules /opt/module-fuzz/test_libraries/comprehensive_tests \
    --output /opt/module-fuzz/trace_output/bit24.svg \
    --format dot \
    --layout both
```

---

## Color Scheme

All formats use the same color scheme:

| Node Type | Color | Description |
|-----------|-------|-------------|
| External Input | Light Green | Primary inputs (in_flat[...]) |
| Module Input | Light Blue | Module input ports |
| Module Output | Light Yellow | Module output ports |
| External Output | Pink | Target output bit being traced |

### Edge Colors (matplotlib):
- **Blue**: Wire connections
- **Orange**: Module logic/expressions

### Edge Colors (dot):
- **Blue**: Wire connections (penwidth 1.5)
- **Orange**: Module logic (penwidth 2)
- **Green text**: Expression labels on logic edges
- **Blue text**: Bit mapping labels on wire edges

---

## Comparison Table

| Feature | matplotlib | dot |
|---------|-----------|-----|
| **Speed** | Slow | Fast |
| **Max Nodes** | ~30 | 100+ |
| **Lines** | Straight/ortho | Curved or straight |
| **Layouts** | Hierarchical only | Hierarchical, Compact, Both |
| **Hangs?** | Yes (large graphs) | Never |
| **Editable** | No | Yes (DOT format) |
| **Export formats** | SVG only | SVG, PNG, PDF, DOT |
| **Legend** | Yes | No |
| **Module labels** | In edges | On nodes |

---

## Troubleshooting

### matplotlib hangs
**Solution:** Use `--format dot` instead

### "graphviz not found" error
**Solution:** Install graphviz:
```bash
apt-get install graphviz
```

### Graph too large to view
**Solution:** 
1. Use `--layout compact` for smaller visualization
2. View the .dot file in a text editor to see connections
3. Use a DOT file viewer with zoom/pan capabilities

### Need to edit the graph
**Solution:** 
1. Use `--format dot` to generate .dot file
2. Edit the .dot file manually
3. Regenerate: `dot -Tsvg file.dot -o file.svg`

---

## What Gets Traced

The tracer follows:

### ✅ Supported
- Combinational logic (`assign` statements)
- Sequential logic (`always @(posedge clk)` blocks)
- Wire declarations with assignments (`wire x = expr;`)
- Intermediate signal expansion (recursive)
- Module input/output mappings
- Bit-level wire connections

### ❌ Not Traced
- Clock signals (ignored)
- Reset signals (ignored)
- Testbench signals
- Non-data path logic

---

## Output Files

### matplotlib format:
- `<output>.svg` - Single SVG file

### dot format (single layout):
- `<output>.svg` - SVG visualization
- `<output>.dot` - DOT source file (editable)

### dot format (both layouts):
- `<basename>_hierarchical.svg` - Hierarchical view
- `<basename>_hierarchical.dot` - DOT source
- `<basename>_compact.svg` - Compact view
- `<basename>_compact.dot` - DOT source

---

## Recommendations

### For Quick Debugging:
```bash
--format dot --layout compact
```

### For Presentation/Publication:
```bash
--format matplotlib  # If graph is small
--format dot --layout hierarchical  # If graph is large
```

### For Exploration (Best Option):
```bash
--format dot --layout both
```
This gives you both perspectives and you can choose which is clearer.

---

## Recent Improvements

1. ✅ Added sequential logic support (always @posedge blocks)
2. ✅ Added wire declaration parsing (wire x = expr)
3. ✅ Added recursive intermediate signal expansion
4. ✅ Added multiple layout options
5. ✅ Added DOT format for large graphs
6. ✅ Fixed missing inputs in arithmetic_reduce and other modules

---

Last updated: 2025-11-12

