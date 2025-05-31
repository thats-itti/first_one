-- Basic settings
vim.g.mapleader = ' '  -- Set space as leader key

-- Options
vim.opt.number = true          -- Line numbers
vim.opt.relativenumber = true  -- Relative line numbers
vim.opt.mouse = 'a'           -- Mouse support
vim.opt.tabstop = 4           -- Tab size
vim.opt.shiftwidth = 4        -- Indent size
vim.opt.expandtab = true      -- Use spaces instead of tabs

-- Load plugins
require('plugins')

-- Key mappings
local map = vim.keymap.set

-- File tree (nvim-tree)
map('n', '<leader>e', ':NvimTreeToggle<CR>', { silent = true, desc = 'Toggle file explorer' })

-- Tagbar (symbols-outline)
map('n', '<leader>t', ':SymbolsOutline<CR>', { silent = true, desc = 'Toggle symbols outline' })

-- Buffer navigation
map('n', '<leader>bn', ':bnext<CR>', { silent = true, desc = 'Next buffer' })
map('n', '<leader>bp', ':bprevious<CR>', { silent = true, desc = 'Previous buffer' })






-- Auto-install packer if not installed
local ensure_packer = function()
  local fn = vim.fn
  local install_path = fn.stdpath('data')..'/site/pack/packer/start/packer.nvim'
  if fn.empty(fn.glob(install_path)) > 0 then
    fn.system({'git', 'clone', '--depth', '1', 'https://github.com/wbthomason/packer.nvim', install_path})
    vim.cmd [[packadd packer.nvim]]
    return true
  end
  return false
end

local packer_bootstrap = ensure_packer()

-- Initialize plugins
return require('packer').startup(function(use)
  -- Package manager
  use 'wbthomason/packer.nvim'

  -- File tree (nvim-tree)
  use {
    'nvim-tree/nvim-tree.lua',
    requires = {
      'nvim-tree/nvim-web-devicons', -- optional icons
    },
    config = function()
      require('nvim-tree').setup({
        view = {
          width = 35,
        },
        filters = {
          dotfiles = false,
        },
      })
    end
  }

  -- Tagbar alternative (symbols-outline)
  use {
    'simrat39/symbols-outline.nvim',
    config = function()
      require('symbols-outline').setup({
        position = 'right',
        width = 25,
      })
    end
  }

  -- Auto-install on first run
  if packer_bootstrap then
    require('packer').sync()
  end
end)