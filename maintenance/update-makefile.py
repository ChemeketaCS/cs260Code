#!/usr/bin/env python3
from pathlib import Path


def is_custom(makefile_path: Path) -> bool:
    """Return True if the Makefile starts with a custom marker.

    A Makefile is treated as custom if the very first line equals
    "# !CUSTOM!" or "#!CUSTOM!" (ignoring leading/trailing whitespace).
    """
    try:
        with makefile_path.open("r", encoding="utf-8") as f:
            first_line = f.readline()
    except UnicodeDecodeError:
        with makefile_path.open("r", encoding="latin-1") as f:
            first_line = f.readline()
    line = first_line.strip()
    return line in ("# !CUSTOM!", "#!CUSTOM!")


def main() -> int:
    # Repo root is the parent of the maintenance directory containing this script
    repo_root = Path(__file__).resolve().parent.parent
    master_path = Path(__file__).resolve().parent / "Makefile-master"

    if not master_path.exists():
        print(f"Master Makefile not found: {master_path}")
        return 1

    try:
        master_content = master_path.read_text(encoding="utf-8")
    except UnicodeDecodeError:
        master_content = master_path.read_text(encoding="latin-1")

    week_dirs = []
    updated = []
    skipped = []

    # Find all directories
    for p in repo_root.glob("*"):
        if p.is_dir():
            week_dirs.append(p)

    # Process Makefiles inside each directory (recursively)
    for wd in week_dirs:
        for mk in wd.rglob("Makefile"):
            if not mk.is_file():
                continue

            try:
                if is_custom(mk):
                    skipped.append(mk)
                    continue
            except Exception as e:
                print(f"Skipping unreadable file {mk}: {e}")
                skipped.append(mk)
                continue

            try:
                mk.write_text(master_content, encoding="utf-8")
                updated.append(mk)
            except UnicodeEncodeError:
                mk.write_text(master_content, encoding="latin-1")
                updated.append(mk)
            except Exception as e:
                print(f"Failed to update {mk}: {e}")

    # Summary
    print(f"Found Week* directories: {len(week_dirs)}")
    print(f"Updated Makefiles: {len(updated)}")
    for path in updated:
        try:
            print(f"UPDATED: {path.relative_to(repo_root)}")
        except ValueError:
            print(f"UPDATED: {path}")
    print(f"Skipped custom Makefiles: {len(skipped)}")
    for path in skipped:
        try:
            print(f"SKIPPED (custom): {path.relative_to(repo_root)}")
        except ValueError:
            print(f"SKIPPED (custom): {path}")

    return 0

if __name__ == "__main__":
    import sys

    sys.exit(main())
