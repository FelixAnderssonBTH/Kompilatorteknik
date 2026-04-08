#!/bin/bash
make clean
make compiler

mkdir -p cfg_output

for file in test_files/valid/*.java; do
  name=$(basename "$file" .java)
  echo "Processing $name..."
  ./compiler "$file"

  if [ -f cfg.dot ]; then
    dot -Tpdf cfg.dot -o "cfg_output/${name}_cfg.pdf"
    mv cfg.dot "cfg_output/${name}_cfg.dot"
  fi
done

echo "Done! Check cfg_output/"
