# 🛠️ Neos

_**neos** - borrowed from Greek neo-, combining form from néos "young, fresh, new" [Merriam-Webster]_

A simple, interactive Bash script to **generate a new project** from a template. It includes colorful terminal messages, automatic Git initialization, and support for C-style project scaffolding.

## 📦 Features

- 🔧 Generates a project from a selected template
- 🎨 Color-coded messages for readability
- 📁 Automatically creates `src` and `include` directories for C projects
- 📝 Replaces placeholder `DEFAULT` in filenames and file contents with your project name
- 🧪 Ready for further extension (e.g., add `tests/` directory)
- 🌱 Optionally initializes a Git repository

## 📂 Project Structure

```
project-generator/
├── templates/
│   ├── program.c/     # C standalone program template directory
│   ├── library.c/     # C library template directory
│   ├── my_template/   # Your custom templates go here
├── neos.sh            # The project generation script
```

---

## 🚀 Usage

```bash
./neos.sh <PROJECT_NAME>
```

If you don't pass a project name, the script will show a usage help message.

### Example:

```bash
./neos.sh myapp
```

1. You'll be prompted to choose a template from the `templates/` folder.
2. The script will copy the selected template into a new folder named `myapp/`.
3. All occurrences of `DEFAULT` in filenames and content will be replaced with `myapp`.
4. If the template was `program.c`, `src/` and `include/` directories will be created.
5. You'll be asked if you want to initialize a Git repository.

## 🧠 Notes

- Make sure you have a `templates/` folder in the same directory as the script.
- Template files should use `DEFAULT` as a placeholder name (in file content and optionally in file names).
- Git is optional but recommended for version control.

## 🛑 Exit Codes

- `1` - No project name provided
- `2` - Missing `templates/` directory
- `3` - Project directory already exists
- `1` - Git not installed (if selected)

## 📌 TODO

- [ ] Add support for test directories
- [ ] Improve error handling and input validation
- [ ] Allow custom template variables beyond `DEFAULT`

## 📄 License

MIT License

## 🤝 Contributing

Pull requests are welcome! Feel free to suggest improvements or open issues.

## References

- [Dr. Jonas Birch: bashbs](https://youtu.be/mRHy0e58S0s?feature=shared)
- [Stewart Weiss Make-Tutorial](https://gitlab.com/stewartweiss/Make-Tutorial)
