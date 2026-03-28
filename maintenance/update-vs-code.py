#!/usr/bin/env python3
from pathlib import Path
import shutil


TEMPLATE_FILES = [
    "c_cpp_properties.json",
    "settings.json",
    "launch.json",
    "tasks.json",
]


def rel_or_abs(path: Path, root: Path) -> str:
    try:
        return str(path.relative_to(root))
    except ValueError:
        return str(path)

def main() -> int:
    # Repo root is the parent of the maintenance directory containing this script.
    repo_root = Path(__file__).resolve().parent.parent
    templates_dir = Path(__file__).resolve().parent / "vscode-master"

    if not templates_dir.is_dir():
        print(f"Template directory not found: {templates_dir}")
        return 1

    missing_templates = [name for name in TEMPLATE_FILES if not (templates_dir / name).is_file()]
    if missing_templates:
        print("Missing template files in vscode-master:")
        for name in missing_templates:
            print(f"  - {name}")
        return 1

    vscode_dirs = [p for p in repo_root.rglob(".vscode") if p.is_dir()]

    copied = []
    failed = []
    attempted = 0

    for vsd in vscode_dirs:
        for name in TEMPLATE_FILES:
            src = templates_dir / name
            dst = vsd / name
            attempted += 1

            try:
                shutil.copy2(src, dst)
                copied.append(dst)
            except Exception as e:
                failed.append((dst, e))

    # Summary
    print(f"Found .vscode directories: {len(vscode_dirs)}")

    for path in copied:
        print(f"COPIED: {rel_or_abs(path, repo_root)}")

    for path, error in failed:
        print(f"FAILED: {rel_or_abs(path, repo_root)} ({error})")

    return 0 if not failed else 2

if __name__ == "__main__":
    import sys
    sys.exit(main())
